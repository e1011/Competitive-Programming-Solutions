#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

namespace Input {
    struct PresentationError : public std::exception {};
    struct IntegerParsingError : public PresentationError {};
    struct WhitespaceError : public PresentationError {};
    struct RequirementFailure : public std::exception {};
    struct IntegerRangeError : public RequirementFailure {};

    struct ValidatorErrorHandler {
    public:
        template <class E> void handle(const E &e) {
            throw e;
        }
    };

    const bool IDENTICAL = true;

    template <class ErrorHandler, const bool IDENTICAL_WHITESPACE> struct Reader : public ErrorHandler {
    private:
        std::istream &stream;
        bool hasLast;
        bool skipToNextLine;
        char last;

        bool isWhitespace(char c) {
            if (IDENTICAL_WHITESPACE) return c == ' ' || c == '\n';
            return isspace(c);
        }

        bool isNewLine(char c) {
            if (IDENTICAL_WHITESPACE) return c == '\n';
            return c == '\n' || c == '\r';
        }

        bool isEOF(char c) {
            return c == std::char_traits<char>::eof();
        }

        char peekChar() {
            if (!hasLast) last = stream.get();
            hasLast = true;
            return last;
        }

        char getChar() {
            char ret = peekChar();
            hasLast = false;
            return ret;
        }

        void skipWhitespace() {
            while (isWhitespace(peekChar()) && (skipToNextLine || !isNewLine(peekChar()))) getChar();
            skipToNextLine = false;
        }

    public:
        template <class E> void require(bool expr, const E &e) {
            if (!expr) ErrorHandler::handle(e);
        }

        template <class ...Args> Reader(std::istream &stream, Args &&...args)
                : ErrorHandler(std::forward<Args>(args)...), stream(stream), hasLast(false), skipToNextLine(true) {}

        long long readInt(long long minValid = std::numeric_limits<long long>::min(),
                          long long maxValid = std::numeric_limits<long long>::max()) {
            if (!IDENTICAL_WHITESPACE) skipWhitespace();
            std::string token = "";
            while (isdigit(peekChar()) || peekChar() == '-') token.push_back(getChar());
            long long ret = 0;
            try {
                ret = std::stoll(token);
            } catch (std::invalid_argument &) {
                ErrorHandler::handle(IntegerParsingError());
            } catch (std::out_of_range &) {
                ErrorHandler::handle(IntegerParsingError());
            }
            require(minValid <= ret && ret <= maxValid, IntegerRangeError());
            return ret;
        }

        void readSpace() {
            require(isWhitespace(peekChar()) && !isNewLine(peekChar()), WhitespaceError());
            getChar();
        }

        void readNewLine() {
            if (!IDENTICAL_WHITESPACE) skipWhitespace();
            skipToNextLine = true;
            require((!IDENTICAL_WHITESPACE && isEOF(peekChar())) || isNewLine(getChar()), WhitespaceError());
        }

        void readEOF() {
            skipToNextLine = true;
            if (!IDENTICAL_WHITESPACE) skipWhitespace();
            require(isEOF(getChar()), WhitespaceError());
        }
    };

    using Validator = Reader<ValidatorErrorHandler, IDENTICAL>;
}

vector <vector <int>> dp(0);
vector <vector <int>> graph(0);
vector <vector <int>> costs(0);

int main() {
    Input::Validator in(cin);
	int n, q, k;
	n = in.readInt(1, 1000);
	in.readSpace();
	q = in.readInt(1, 1000000);
	in.readNewLine();
	
	graph = vector <vector <int>> (n, vector <int> (0));
	costs = vector <vector <int>> (n, vector <int> (0));
	for (int i = 0; i < n-1; i ++) {
		int a, b, c;
		a = in.readInt(1, n);
		in.readSpace();
		b = in.readInt(1, n);
		in.readSpace();
		c = in.readInt(1, 1000);
		in.readNewLine();
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
	}
	
	k = 2*costs[0][0];
	
	dp = vector <vector <int>> (n, vector <int> (k, -1));
	priority_queue <vector <int>, vector <vector <int>>, greater <vector<int>>> pq;
	pq.push({0, 0, 0});
	
    while (!pq.empty()) {
        int mod=pq.top()[0], rem=pq.top()[1], node=pq.top()[2];
        pq.pop();

        if (dp[node][rem] == -1) {
            dp[node][rem] = mod;
            for (int i = 0; i < graph[node].size(); i ++) {
				int x = dp[graph[node][i]][(rem+costs[node][i]) % k];
				if (x == -1 || mod+(rem+costs[node][i])/k < x) {
					pq.push({mod+(rem+costs[node][i])/k, (rem+costs[node][i]) % k, graph[node][i]});
				}
            }
        }
    }
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		a = in.readInt(1, n);
		in.readSpace();
		b = in.readInt(1, 1000);
		in.readNewLine();
		if (dp[a-1][b % k] != -1 && dp[a-1][b % k] <= b/k) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
    in.readEOF();
    return 0;
}

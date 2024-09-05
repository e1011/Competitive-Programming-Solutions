#include <bits/stdc++.h>

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

int main() {
	Input::Validator in(cin);
	int n, m, k, lasttime=0, counter=0, inmeteor=0;
	n = in.readInt(1, 1000000000);
	in.readSpace();
	m = in.readInt(1, 10000);
	in.readSpace();
	k = in.readInt(1, 1000000000);
	in.readNewLine();
	
	
	vector <vector <int>> possibleplaces(0);
	possibleplaces.push_back({0, 0});
	possibleplaces.push_back({0, 1});
	
	for (int i = 0; i < m; i ++) {
		int a, b, t;
		a = in.readInt(0, n);
		in.readSpace();
		b = in.readInt(a, n);
		in.readSpace();
		t = in.readInt(1, 1000000000);
		in.readNewLine();
		vector <vector <int>> newpossibleplaces1(0), newpossibleplaces2(0);
		for (int j = 0; j < possibleplaces.size(); j ++) {
			if (possibleplaces[j][1] == 0) {
				newpossibleplaces1.push_back({max(possibleplaces[j][0]-(t-lasttime)*k, 0), 0});
			}
			else if (possibleplaces[j][1] == 1) {
				newpossibleplaces1.push_back({min(possibleplaces[j][0]+(t-lasttime)*k, n), 1});
			}
		}
		lasttime = t;
		newpossibleplaces1.push_back({a-1, 2});
		newpossibleplaces1.push_back({b+1, 0, 1});
		sort(newpossibleplaces1.begin(), newpossibleplaces1.end());
		
		for (int j = 0; j < newpossibleplaces1.size(); j ++) {
			if (newpossibleplaces1[j][1] == 2) {
				inmeteor = 1;
				if (counter > 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 1});
				}
			}
			else if (newpossibleplaces1[j].size() == 3) {
				inmeteor = 0;
				if (counter > 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 0});
				}
			}
			else if (newpossibleplaces1[j][1] == 0) {
				if (counter == 0 && inmeteor == 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 0});
				}
				counter += 1;
			}
			else {
				counter -= 1;
				if (counter == 0 && inmeteor == 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 1});
				}
			}
		}
		possibleplaces = newpossibleplaces2;
		counter = 0;
	}
	
	if (possibleplaces.size()) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}

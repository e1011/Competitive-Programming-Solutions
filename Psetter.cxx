#include <iostream>

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
    
    ll N, x, y, A, B;
    N = in.readInt(2, 100000);
    in.readNewLine();

    for(int i = 0; i < N; i++) {
        x = in.readInt(1, 1000000);
        in.readSpace();
        y = in.readInt(1, 1000000);
        in.readSpace();
        A = in.readInt(-2e12, 2e12);
        in.readSpace();
        B = in.readInt(-2e12, 2e12);
        in.readNewLine();
    }

    in.readEOF();
    return 0;
}

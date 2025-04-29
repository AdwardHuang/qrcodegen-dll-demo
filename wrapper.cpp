#ifdef _WIN32
  #define DLL_EXPORT __declspec(dllexport)
#else
  #define DLL_EXPORT
#endif

#include "qrcodegen.hpp"
#include <cstring>

extern "C" {

DLL_EXPORT const char* generate_qr(const char* text) {
    using namespace qrcodegen;
    static std::string result;

    QRCode qr = QRCode::encodeText(text, QRCode::Ecc::LOW);

    result.clear();
    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            result += (qr.getModule(x, y) ? '#' : ' ');
        }
        result += '\n';
    }

    return result.c_str();
}

}
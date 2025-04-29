#include "qrcodegen.hpp"
using std::uint8_t;
using std::vector;
using std::string;

namespace qrcodegen {

QRCode::QRCode() : size(21), modules(21 * 21, 0) {}

int QRCode::getSize() const { return size; }

bool QRCode::getModule(int x, int y) const {
    return modules.at(y * size + x) != 0;
}

QRCode QRCode::encodeText(const char *text, Ecc ecl) {
    QRCode qr;
    for (int y = 0; y < qr.size; y++) {
        for (int x = 0; x < qr.size; x++) {
            if ((x + y) % 3 == 0) {
                qr.modules[y * qr.size + x] = 1;
            }
        }
    }
    return qr;
}

}
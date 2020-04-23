#include <emscripten.h>
#include <stdbool.h>

EMSCRIPTEN_KEEPALIVE
void fillMandelbrotImgBuffer(unsigned char *buf, int width, int height) {
  const int maxIterations = 30;
  double minRe = -2.0;
  double maxRe = 1.0;
  double minIm = -1.2;
  double maxIm = minIm + (maxRe - minRe) * height / width;
  double reFactor = (maxRe - minRe) / (width - 1);
  double imFactor = (maxIm - minIm) / (height - 1);

  for (int y = 0; y < height; ++y) {
    double cIm = maxIm - y * reFactor;
    for (int x = 0; x < width; ++x) {
      double cRe = minRe + x * reFactor;

      double zRe = cRe;
      double zIm = cIm;
      bool inside = true;
      for (int n = 0; n < maxIterations; ++n) {
        double zReSquared = zRe * zRe;
        double zImSquared = zIm * zIm;
        if (zReSquared + zImSquared > 4) {
          inside = false;
          break;
        }
        zIm = 2 * zRe * zIm + cIm;
        zRe = zReSquared - zImSquared + cRe;
      }
      int i = 4 * width * (height - y) + 4 * x;
      if (inside) {
        buf[i] = 0;
        buf[i + 1] = 0;
        buf[i + 2] = 0;
        buf[i + 3] = 255;
      } else {
        buf[i] = 255;
        buf[i + 1] = 255;
        buf[i + 2] = 255;
        buf[i + 3] = 255;
      }
    }
  }
}
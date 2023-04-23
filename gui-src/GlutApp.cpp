#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream) {
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);

  // // read1
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("pretty-mandel-1.ppm");
  // takeAction("read1", mMenuData, mActionData);
  
  // // copy
  // mOutputStream.clear();
  // mInputStream.clear();
  // mInputStream.str("");
  // takeAction("copy", mMenuData, mActionData);
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}

void GlutApp::display() {
  PPM& p = mActionData.getOutputImage();
  double max = static_cast<double>(p.getMaxColorValue());
  double r, g, b;
  int row, column;
  glBegin( GL_POINTS );
  for(row = 0; row < p.getHeight(); row++) {
    for(column = 0; column < p.getWidth(); column++) {
      r = p.getChannel(row, column, 0) / max;
      g = p.getChannel(row, column, 1) / max;
      b = p.getChannel(row, column, 2) / max;
      glColor3d(r, g, b);
      glVertex2i(column, p.getHeight()-row-1);
    }
  }
  glEnd( );
}

void GlutApp::selectJulia(){
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("julia", mMenuData, mActionData);
}
void GlutApp::selectMandelbrot(){
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("mandelbrot", mMenuData, mActionData);
}
void GlutApp::selectComplexFractal(){
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("complex-fractal", mMenuData, mActionData);
}
void GlutApp::configureGrid(int max){
  // grid
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << max;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);
}
void GlutApp::juliaParameters(double a, double b){
  // julia-parameters
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << a << " " << b;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);

}
void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max ){
  // fractal-plane-size
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " "<< y_min << " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);


}

void GlutApp::fractalCalculate(){
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("fractal-calculate", mMenuData, mActionData);

}

void GlutApp::gridApplyColorTable(){
    mOutputStream.clear();
    mOutputStream.str("");
    mInputStream.clear();
    mInputStream.str("");
    takeAction("grid-apply-color-table", mMenuData, mActionData);
    
}

void GlutApp::createJulia() {
    selectJulia();
    configureGrid(100);
    juliaParameters(-0.2, .120);
    fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createJulia2() {
    selectJulia();
    configureGrid(100);
    juliaParameters(-0.7, .03);
    fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createMandelbrot() {
    selectMandelbrot();
    configureGrid(100);
    fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
    fractalCalculate();
    gridApplyColorTable();
}

void GlutApp::createMandelbrot2() {
    selectMandelbrot();
    configureGrid(100);
    fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createComplexFractal() {
    selectComplexFractal();
    configureGrid(100);
    fractalPlaneSize(-2.0, 2.0, -2.0, 2.0);
    fractalCalculate();
    gridApplyColorTable();
}
void GlutApp::createComplexFractal2() {
    selectComplexFractal();
    configureGrid(100);
    fractalPlaneSize(-1.5, 1.5, -1.5, 1.5);
    fractalCalculate();
    gridApplyColorTable();
}

#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream), mMinX(-2.0), mMaxX(2.0), mMinY(-2.0), mMaxY(2.0), mInteractionMode(IM_FRACTAL), mFractalMode(M_MANDELBROT), mMaxNumber(200), mNumColor(32){
  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);
  juliaParameters(0.3, 1.8);
  setColorTable();
  createFractal();

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
  if(mInteractionMode == IM_FRACTAL){
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
  
  }else if(mInteractionMode == IM_COLORTABLE){
    displayColorTable();
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


void GlutApp::displayColorTable(){
glBegin(GL_POINTS);
    for (int row = 0; row < mHeight; row++){
        for (int column = 0; column < mWidth; column++){
             int i = column * mNumColor  / mWidth;
             Color color = mActionData.getTable()[i];
             int red = color.getRed() / 255.0;
             int green = color.getGreen() / 255.0;
             int blue = color.getBlue() / 255.0;
             glColor3d(red,green,blue);
             glVertex2i(column, row);
        }
    }
}
void GlutApp::setInteractionMode(InteractionMode mode){
mInteractionMode = mode;
}
void GlutApp::setColorTable(){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mNumColor;
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-table-size", mMenuData, mActionData);

  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue() << " " << mNumColor - 1 << " " << mColor2.getRed() << " " << mColor2.getGreen() << " "<< mColor2.getBlue();
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-gradient", mMenuData, mActionData);

}
void GlutApp::decreaseColorTableSize(){
    if (mNumColor > 10 ){
        mNumColor = mNumColor / 1.1;
        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::increaseColorTableSize(){
    if(mNumColor < 1024){
        mNumColor = mNumColor * 1.1;
        setColorTable();
        gridApplyColorTable();
    }
}
void GlutApp::randomColor1(){
    double red = (std::rand() % 255);
    double green = (std::rand() % 255);
    double blue = (std::rand() % 255);
    mColor1.setRed(red);
    mColor1.setGreen(green);
    mColor1.setBlue(blue);
    setColorTable();
    gridApplyColorTable();

}
void GlutApp::randomColor2(){
    double red = (std::rand() % 255);
    double green = (std::rand() % 255);
    double blue = (std::rand() % 255);
    mColor2.setRed(red);
    mColor2.setGreen(green);
    mColor2.setBlue(blue);
    setColorTable();
    gridApplyColorTable();
  
}
void GlutApp::zoomIn(){
   double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
   mMinX += dx;
   mMaxX -= dx;
   double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
   mMinY += dy;
   mMaxY -= dy;
}

void GlutApp::zoomOut(){
    double dx = (1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
    mMinX -= dx;
    mMaxX += dx;
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    mMinY -= dy;
    mMaxY += dy;
}

void GlutApp::moveLeft(){
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    if (mMinX - dx >= -2.0){
        mMinX -= dx;
        mMaxX -= dx;
    }

}

void GlutApp::moveRight(){
    double dx = (1.0 - 0.9)*(mMaxX-mMinX) / 2.0;
    if (mMaxX + dx >= -2.0){
        mMinX += dx;
        mMaxX += dx;
    }
}

void GlutApp::moveUp(){
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if (mMaxY + dy <= -2.0){
        mMinY += dy;
        mMaxY += dy;
    }

}

void GlutApp::moveDown(){
    double dy = (1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
    if (mMinY - dy >= -2.0){
        mMinY -= dy;
        mMaxY -= dy;
    }
}

void GlutApp::setFractalMode(FractalMode mode){
    mFractalMode = mode;

}

void GlutApp::increaseMaxNumber(){
    if (mMaxNumber < 2048){
        mMaxNumber *= 1.1;
    }
}
void GlutApp::decreaseMaxNumber(){
    if (mMaxNumber > 11){
        mMaxNumber /= 1.1;
    }
}
void GlutApp::setAB(int x, int y){
    mActionData.getGrid();
    ComplexFractal *cf = dynamic_cast<ComplexFractal *>(&mActionData.getGrid());
    if (mFractalMode == M_MANDELBROT && cf != 0){
        mA = mMinX + x * cf->getDeltaX();
        mB = mMinY + y * cf->getDeltaY();
    }
}
void GlutApp::resetPlane(){
    mMinX = -2.0;
    mMinY = -2.0;
    mMaxX = 2.0;
    mMaxY = 2.0;
}
void GlutApp::createFractal(){
    if (mFractalMode == M_MANDELBROT){
        selectMandelbrot();
    }
    else if(mFractalMode == M_JULIA){
        selectJulia();
        juliaParameters(mA, mB);
    }
    else if (mFractalMode == M_COMPLEX){
        selectComplexFractal();
    }
    configureGrid(mMaxNumber);
    fractalPlaneSize(mMinX, mMaxX, mMinY, mMaxY);
    fractalCalculate();
    gridApplyColorTable();
}

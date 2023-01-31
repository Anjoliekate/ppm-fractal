#ifndef _IMAGE_H_
#define _IMAGE_H_
#include <vector>
class Image{
    public:
    Image();
    Image(const int& height_input, const int& width_input);
    int getHeight() const;
    int getWidth() const;
    bool indexValid( const int& row, const int& column, const int& channel ) const;
    int index( const int& row, const int& column, const int& channel ) const; 
    int getChannel( const int& row, const int& column, const int& channel) const;
    void setHeight( const int& height );
    void setWidth( const int& width );
    void setChannel(const int& row, const int& column, const int& channel, const int& value );
    std::vector<int> imageVector;

    private:
        int height;
        int width;
};

#endif /*_IMAGE_H_*/
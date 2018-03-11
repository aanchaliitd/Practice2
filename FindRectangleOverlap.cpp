#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle
{
private:
    // coordinates of bottom left corner
    int leftX_;
    int bottomY_;

    // dimensions
    int width_;
    int height_;

public:
    Rectangle() :
        leftX_(0),
        bottomY_(0),
        width_(0),
        height_(0)
    {
    }

    Rectangle(int leftX, int bottomY, int width, int height) :
        leftX_(leftX),
        bottomY_(bottomY),
        width_(width),
        height_(height)
    {
    }

    int getLeftX() const
    {
        return  leftX_;
    }

    int getBottomY() const
    {
        return  bottomY_;
    }

    int getWidth() const
    {
        return  width_;
    }

    int getHeight() const
    {
        return  height_;
    }

    bool operator==(const Rectangle& other) const
    {
        return
            leftX_ == other.leftX_
            && bottomY_ == other.bottomY_
            && width_ == other.width_
            && height_ == other.height_;
    }

    bool operator!=(const Rectangle& other) const
    {
        return !(*this == other);
    }
};

Rectangle ComputeIntersection(const Rectangle& rect1,
                              const Rectangle& rect2)
{
    int left1 = rect1.getLeftX();
    int left2 = rect2.getLeftX();
    
    int bottom1 = rect1.getBottomY();
    int bottom2 = rect2.getBottomY();
    
    int width1 = rect1.getWidth();
    int width2 = rect2.getWidth();
    
    int height1 = rect1.getHeight();
    int height2 = rect2.getHeight();
    
    int minX = min(left1, left2);
    int minY = min(bottom1, bottom2);
    
    int maxX = max(left1 + width1, left2 + width2);
    int maxY = max(bottom1 + height1, bottom2 + height2);
    
    if (maxX < (minX + width1 + width2) && maxY < (minY + height1 + height2)) {
        // intersection found. Compute the intersection.
        int result_left = max(left1, left2);
        int result_bottom = max(bottom1, bottom2);
        
        int result_width = (width1 + width2) - (maxX - minX);
        int result_height = (height1 + height2) - (maxY - minY);
        
        return Rectangle(result_left, result_bottom,
                         result_width, result_height);
    }
    else {
        // Intersection not found. Return an empty rectangle.
        return Rectangle();   
    }
    
}                              

int main ()
{
    Rectangle aanchal(10, 10, 100, 100);
    Rectangle jayash(110, 10, 100, 100);
    
    Rectangle result = ComputeIntersection(aanchal, jayash);
    
    if (result == Rectangle()) 
    {
        cout << "No intersection found \n";   
    }
    else {
        cout << "Intersection found \n";
        cout << "left : " << result.getLeftX()
             << " bottom : " << result.getBottomY()
             << " width : " << result.getWidth()
             << " height : " << result.getHeight() << endl; 
    }
    return 0;
}


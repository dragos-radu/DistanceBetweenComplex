#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<cstdio>

using namespace std;

class Point{

protected:
    vector<double>mCoordinates;
    double mDistance;

    friend class Point2D;
    friend class Point3D;
    friend class Point4D;

public:
    virtual void print()=0;
    virtual void calculateDistance()=0;
    virtual Point* multiply(Point* p)=0;

    Point()
    {

    }
    double getDistance()
    {
        calculateDistance();
        return mDistance;
    }
};

class Point2D : public Point{

public:
    Point2D()
    {
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point2D(double x,double y)
    {
        mCoordinates.push_back(x);
        mCoordinates.push_back(y);
    }

    Point* multiply(Point* altul){

        double x;
        double y;
        if(altul->mCoordinates.size()==2)
        {
            x=mCoordinates[0]*altul->mCoordinates[0]-mCoordinates[1]*altul->mCoordinates[1];
            y=mCoordinates[0]*altul->mCoordinates[1]+mCoordinates[1]*altul->mCoordinates[0];
        }
        if(altul->mCoordinates.size()==3)
        {
            x=mCoordinates[0]*altul->mCoordinates[0]-mCoordinates[1]*altul->mCoordinates[1];
            y=mCoordinates[0]*altul->mCoordinates[1]+mCoordinates[1]*altul->mCoordinates[0];
        }
        if(altul->mCoordinates.size()==4)
        {
            x=mCoordinates[0]*altul->mCoordinates[0]-mCoordinates[1]*altul->mCoordinates[1];
            y=mCoordinates[0]*altul->mCoordinates[1]+mCoordinates[1]*altul->mCoordinates[0];
        }
        Point* p2=new Point2D(x,y);
        return p2;
    }

    void calculateDistance()
    {
        double distance=sqrt(mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]);

        mDistance=distance;
    }

    void print()
    {
        printf("%.3lf",mCoordinates[0]);
        if(mCoordinates[1]<0)
        {
            printf("%.3lfi",mCoordinates[1]);

        }
        else
        {
            printf("%+.3lfi",mCoordinates[1]);

        }
        cout<<" -> ";
        printf("%.3lf",getDistance());
    }
};

class Point3D : public Point{

public:
    Point3D()
    {
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point3D(double x,double y, double z)
    {
        mCoordinates.push_back(x);
        mCoordinates.push_back(y);
        mCoordinates.push_back(z);

    }
    Point* multiply(Point* p1){

        double x;
        double y;
        double z;
        if(p1->mCoordinates.size()==4)
        {
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1]-mCoordinates[2]*p1->mCoordinates[2];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[0]*p1->mCoordinates[2]+mCoordinates[2]*p1->mCoordinates[0];
        }
        if(p1->mCoordinates.size()==3)
        {
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1]-mCoordinates[2]*p1->mCoordinates[2];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[0]*p1->mCoordinates[2]+mCoordinates[2]*p1->mCoordinates[0];
        }
        if(p1->mCoordinates.size()==2)
        {
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[2]*p1->mCoordinates[0];
        }
        Point* p3=new Point3D(x,y,z);
        return p3;
    }

    void calculateDistance()
    {
        double distance=mCoordinates[0]*mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]*mCoordinates[1]+mCoordinates[2]*mCoordinates[2]*mCoordinates[2];
        distance=pow(distance,1.0/3.0);

        mDistance=distance;

    }

    void print()
    {
        printf("%.3lf",mCoordinates[0]);
        if(mCoordinates[1]<0)
        {
            printf("%.3lfi",mCoordinates[1]);

        }
        else
        {
            printf("%+.3lfi",mCoordinates[1]);

        }
        if(mCoordinates[2]<0)
        {
            printf("%.3lfj",mCoordinates[2]);

        }
        else
        {
            printf("%+.3lfj",mCoordinates[2]);

        }
        cout<<" -> ";
        printf("%.3lf",getDistance());
    }
};

class Point4D : public Point{


public:
    Point4D()
    {
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mCoordinates.push_back(0);
        mDistance=0;
    }
    Point4D(double x,double y, double z,double w)
    {
        mCoordinates.push_back(x);
        mCoordinates.push_back(y);
        mCoordinates.push_back(z);
        mCoordinates.push_back(w);

    }
    Point* multiply(Point* p1){
        double x;
        double y;
        double z;
        double w;
        if(p1->mCoordinates.size()==4){
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1]-mCoordinates[2]*p1->mCoordinates[2]-mCoordinates[3]*p1->mCoordinates[3];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[0]*p1->mCoordinates[2]+mCoordinates[2]*p1->mCoordinates[0];
            w=mCoordinates[0]*p1->mCoordinates[3]+mCoordinates[3]*p1->mCoordinates[0];
        }
        if(p1->mCoordinates.size()==3){
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1]-mCoordinates[2]*p1->mCoordinates[2];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[0]*p1->mCoordinates[2]+mCoordinates[2]*p1->mCoordinates[0];
            w=mCoordinates[3]*p1->mCoordinates[0];
        }
        if(p1->mCoordinates.size()==2)
        {
            x=mCoordinates[0]*p1->mCoordinates[0]-mCoordinates[1]*p1->mCoordinates[1];
            y=mCoordinates[0]*p1->mCoordinates[1]+mCoordinates[1]*p1->mCoordinates[0];
            z=mCoordinates[2]*p1->mCoordinates[0];
            w=mCoordinates[3]*p1->mCoordinates[0];
        }
        Point* p4=new Point4D(x,y,z,w);
        return p4;
    }

    void calculateDistance()
    {
        double distance=sqrt(mCoordinates[0]*mCoordinates[0]*mCoordinates[0]*mCoordinates[0]+mCoordinates[1]*mCoordinates[1]*mCoordinates[1]*mCoordinates[1]+mCoordinates[2]*mCoordinates[2]*mCoordinates[2]*mCoordinates[2]+mCoordinates[3]*mCoordinates[3]*mCoordinates[3]*mCoordinates[3]);
        distance=sqrt(distance);
        mDistance=distance;

    }

    void print()
    {
        printf("%.3lf",mCoordinates[0]);
        if(mCoordinates[1]<0)
        {
            printf("%.3lfi",mCoordinates[1]);

        }
        else
        {
            printf("+%.3lfi",mCoordinates[1]);

        }
        if(mCoordinates[2]<0)
        {
            printf("%.3lfj",mCoordinates[2]);

        }
        else
        {
            printf("+%.3lfj",mCoordinates[2]);

        }
        if(mCoordinates[3]<0)
        {
            printf("%.3lfk",mCoordinates[3]);

        }
        else
        {
            printf("+%.3lfk",mCoordinates[3]);
        }
        cout<<" -> ";
        printf("%.3lf",getDistance());
    }
};
int main(){
    double x,y,z,w;
    vector<Point*>points;
    while(cin>>x)
    {
        int cnt=scanf(";%lf;%lf;%lf", &y, &z, &w);
        if((1 + cnt)==2)
        {
            points.push_back(new Point2D(x, y));
        }
        else if((1 + cnt)==3)
        {
            points.push_back(new Point3D(x, y,z));
        }
        else if((1 + cnt)==4)
        {
            points.push_back(new Point4D(x,y,z,w));
        }

    }
    //for(int i=0;i<points.size();i++)
    //  points[i]->print();
    Point* multiplied;
    double maxDistance=0;

    for(int i=0;i<points.size();i++)
    {
        for(int j=0;j<points.size();j++)
        {
            if(points[i]!=points[j] && points[i]->multiply(points[j])->getDistance()>maxDistance)
            {
                multiplied=points[i]->multiply(points[j]);
                maxDistance=points[i]->multiply(points[j])->getDistance();

            }
        }
    }
    multiplied->print();
    return 0;
}

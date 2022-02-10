#ifndef HINH_H
#define HINH_H

class Hinh //abstract class
{
	public:
		Hinh(double aa=1);
		virtual ~Hinh(){}
		virtual double Dientich() const =0;//thuần ảo
		virtual void Display() const;
	protected:
		double a;
};

#endif

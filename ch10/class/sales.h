#ifndef SALES_H_
#define SALES_H_
namespace SALES {
class Sales {
   private:
    const static int QUARTERS = 4;
    double sales[QUARTERS];
    int num;
    double average;
    double max;
    double min;

   public:
    Sales(const double *ar, int n);
    Sales();
    void Show();
};
}  // namespace SALES
#endif
#ifndef SINGELTONE2_H_
#define SINGELTONE2_H_ value

class Singeltone2{


    public:
        static Singeltone2& newClass();
        static int count;

    private:
        Singeltone2();
        ~Singeltone2();
};
#endif /* ifndef SINGELTONE_H_ */

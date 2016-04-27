#ifndef SINGELTONE_H_
#define SINGELTONE_H_ value

class Singeltone{


    public:
    	static Singeltone *p;
        static Singeltone* newClass();
        static int count;

    private:
        Singeltone();
        ~Singeltone();
};
#endif /* ifndef SINGELTONE_H_ */

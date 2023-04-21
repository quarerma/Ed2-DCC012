class NoArv {


public:
    NoArv(){ };
    ~NoArv(){ };
    void setEsq(NoArv *p) { esq = p; };
    void setInfo(int val) { info = val; };
    void setDir(NoArv *p) { dir = p; };
    NoArv* getEsq()       { return esq; };
    int getInfo()         { return info; };
    NoArv* getDir()       { return dir; };

private:
    NoArv *esq; 
    NoArv *dir; 
    int info; 
};

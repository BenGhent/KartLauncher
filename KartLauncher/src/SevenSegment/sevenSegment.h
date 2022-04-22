class sevenSegment {
    enum kart{
        LEFT,
        RIGHT
    };
    public:
        void init();
        void writeTime(double num, kart kart);
        void writeNum(int num, kart kart, int place, boolean dec);
        void writeWord(String word, kart kart);
        void writeList(int list[8]);
};
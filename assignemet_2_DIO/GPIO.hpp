


class GPIO
{
    public:
        void pinMode(int pinNum , int pinMode); //-> OUTPUT or INPUT;
        void digitalWrite(int pinNum , int pinMode);
        int  digitalRead(int pinNum);
};
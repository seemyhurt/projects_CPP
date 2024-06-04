// verylong.h
// ��������� ������ ������������ ����� �����

#include <cwchar>

const int SZ = 1000;           //������������ ����� ��������

class verylong
{
private:
    wchar_t vlstr[SZ];            //����� ��� ������
    size_t vlen;                  //����� ������ verylong
public:

    verylong() : vlen(0)       //����������� ��� ����������
    {
        vlstr[0] = '\0';
    }
    verylong(const wchar_t s[SZ]) //����������� (1 ��������)
    {
        wcscpy_s(vlstr, s);
        vlen = wcslen(s);
    } //��� ������
    verylong(const unsigned long n) //����������� (1 ���.)
    {                             //��� long int
        _ltow_s(n, vlstr, 10);           //��������� � ������
        _wcsrev(vlstr);                //����������� ��
        vlen = wcslen(vlstr);           //����� �����
    }
    void putvl() const;              //������� �����
    void getvl();       //�������� ����� �� ������������
    verylong operator + (const verylong); //������� �����
    verylong operator * (const verylong); //��������
    verylong multdigit(const int) const; //���������
    verylong mult10(const verylong) const;// �������
    // �������
};
int main();

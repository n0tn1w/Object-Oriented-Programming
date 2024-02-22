#include "engine.h"
#include "StringPiåce.h"
#include "StringCreaterPieceByPiece.h"

void run() {

    //StringPiece p1("Heyy");
    //size_t s = p1.getSize();
    //cout << s << endl;
    //p1.operator<<("  Braaa");
    //cout << p1.getPiece() << endl;
    //size_t s2 = p1.getSize();
    //cout << s2 << endl;
    //p1.operator>>(" kk");
    //cout << p1.getPiece() << endl;
    //size_t s3 = p1.getSize();
    //cout << s3 << endl;
    //p1.operator<<("@@");
    //cout << p1.getPiece() << endl;
    //size_t s4 = p1.getSize();
    //cout << s4 << endl;
    //cout << p1.getPiece() << endl;
    //cout << p1[0] << p1[15] << endl;

    //try {
    //    p1.operator<<("a");
    //    cout << "No error";
    //}
    //catch (const std::out_of_range& e) {
    //    cout << "1";
    //    cerr << e.what() << endl;
    //}
    //catch (const std::length_error& e) {
    //    cout << "2";
    //    cerr << e.what() << endl;
    //}

    //StringPiece p2;
    //p2.setPiece("abbcccdddd");
    //p2.operator<<("@@");
    //cout << p2.getPiece() << endl;

    //p2.remove(Position::begin, 3);
    //cout << p2.getPiece() << endl;
    //p2.operator>>("kkk");
    //cout << p2.getPiece() << endl;
    //p2.remove(Position::begin, 1);
    //cout << p2.getPiece() << endl;
    //p2.remove(Position::begin, 10);
    //p2.operator<<("!!!");
    //cout << p2.getPiece() << endl;
    //p2.changeByIndex('?', 0);
    //p2.changeByIndex('1', 1);
    //cout << p2.getPiece() << endl;
    //p2.remove(Position::end, 3);
    //cout << p2.getPiece() << endl;
    //p2.remove(Position::end, 1);
    //cout << p2.getPiece() << endl;
    //size_t s11 = p2.getSize();
    //cout << s11 << endl;

    //try {
    //    p2.changeByIndex('1', 1);
    //    cout << "No error";
    //}
    //catch (const std::out_of_range& e) {
    //    cout << "Error";
    //    cerr << e.what() << endl;
    //}

    //size_t s22 = p2.getSize();
    //cout << s22 << endl;
    //p2.operator<<(1);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;
    //p2.operator<<(12);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;
    //p2.operator>>(12);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;

    //p2.operator>>("abvd");
    //cout << p2.getPiece() << endl;
    //p2.operator<<(2);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;
    //p2.operator<<(3);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;
    //p2.operator<<(1);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;

    //p2.operator>>(1);
    //cout << p2.getPiece() << endl;
    //cout << p2.getSize() << endl;
    //p2.remove(Position::end, 7);
    //cout << p2.getPiece() << endl;

    //p2.operator<<(8);
    //cout << p2.getPiece() << endl;
    //p2.operator<<(9);
    //cout << p2.getPiece() << endl;
    //p2.operator<<(7);
    //cout << p2.getPiece() << endl;
    //p2.remove(Position::end, 9);
    //StringPiece p3("Heyy");

    //p3.operator<<(1);
    //cout << p3.getPiece() << endl;
    //p3.operator>>(99);
    //cout << p3.getPiece() << endl;
    //p3.operator<<(103);
    //cout << p3.getPiece() << endl;

   /* StringCreaterPieceByPiece sc(3);

    sc.addPiece("test");
    sc.addPiece();
    sc.addPiece("football");
    sc.addPiece();
    sc.addPiece("football");

    sc[1] << " friends ";
    " Hello " >> sc[1];
    10 >> sc[2];

    MyString result1 = sc.getString();
    cout << result1 << endl;

    sc.swap(1, 2);
    MyString result2 = sc.getString();
    cout << result2 << endl;

    sc.remove(1);
    sc.remove(0);
    sc.remove(2);
    sc.remove(3);
    MyString result3 = sc.getString();
    cout << result3 << endl;

    sc.remove(4);
    MyString result43 = sc.getString();
    cout << result43 << endl;

    sc.addPiece("", 4);
    sc.addPiece("", 0);
    sc[4] << "bb";
    sc[4] << "@@";
    sc[4] << 10;
    "!!" >> sc[4];
    11 >> sc[4];
    10 >> sc[0];
    sc[1] << "AWW";
    sc[2] << " ** " ;

    MyString result5 = sc.getString();
    cout << result5 << endl;

    sc[3] << "[]";

    sc.swap(0, 4);
    MyString result6 = sc.getString();
    cout << result6 << endl;
    cin >> sc[3];

    MyString result7 = sc.getString();
    cout << result7 << endl;*/

    StringCreaterPieceByPiece sc(3);
    sc.addPiece();
    sc.addPiece("");
    sc.addPiece();
    cout << sc.getLen();
    StringPiece s;
    s << "abcdabcdabcdabc";
    cout << s.getPiece();
}
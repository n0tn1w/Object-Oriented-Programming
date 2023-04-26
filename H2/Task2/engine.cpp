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

    StringCreaterPieceByPiece sc(3);

    sc.addPiece("test");
    /*sc.addPiece("  ac");*/
    sc.addPiece();
    sc.addPiece("football");

   /* StringPiece p2;
    p2.setPiece("abbcccdddd");
    p2 << "a";
    p2 << "bb";
    cout << p2.getPiece();*/

    sc[1] << " friends ";
    " Hello " >> sc[1];
    10 >> sc[2];


    //cout << sc[0].getPiece() << sc[1].getPiece() << sc[2].getPiece();

    MyString result1 = sc.getString(); // “test Hello friends 10football”
    cout << result1 << endl;

    sc.swap(1, 2);
    MyString result2 = sc.getString(); // “test10football Hello friends”
    cout << result2 << endl;

    sc.remove(1);
    MyString result3 = sc.getString(); // “test10                     Hello friends”
    cout << result3 << endl;
}
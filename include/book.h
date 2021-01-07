#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <map>



class Book{
  enum Testament{OLD=1,NEW};

public:
  struct book_meta {
    int max_chapter;
    int max_verse;
  };
  
  struct A{
    int chapter;
    int verse;
    std::string verse_text;
  };
  
  Book();
  Book(std::string); // book name
  std::string book_name;
  int chapter;
  int verse_num;
  std::string verse_text;

  void say_hi();
  std::map<std::string, book_meta> book_borders = {{"GENESIS", book_meta{50, 67}},{"EXODUS", book_meta{40, 51}},{"LEVITICUS", book_meta{27, 59}},{"NUMBERS", book_meta{36, 89}},{"DEUTERONOMY", book_meta{34, 68}},{"JOSHUA", book_meta{24, 63}},{"JUDGES", book_meta{21, 57}},{"RUTH", book_meta{4, 23}},{"1SAMUEL", book_meta{31, 58}},{"2SAMUEL", book_meta{24, 51}},{"1KINGS", book_meta{22, 66}},{"2KINGS", book_meta{25, 44}},{"1CHRONICLES", book_meta{29, 81}},{"2CHRONICLES", book_meta{36, 42}},{"EZRA", book_meta{10, 70}},{"NEHEMIAH", book_meta{13, 73}},{"ESTHER", book_meta{10, 32}},{"JOB", book_meta{42, 41}},{"PSALMS", book_meta{150, 176}},{"PROVERBS", book_meta{31, 36}},{"ECCLESIASTES", book_meta{12, 29}},{"SONG OF SOLOMON", book_meta{8, 17}},{"ISAIAH", book_meta{66, 38}},{"JEREMIAH", book_meta{52, 64}},{"LAMENTATIONS", book_meta{5, 66}},{"EZEKIEL", book_meta{48, 63}},{"DANIEL", book_meta{12, 49}},{"HOSEA", book_meta{14, 23}},{"JOEL", book_meta{3, 32}},{"AMOS", book_meta{9, 27}},{"OBADIAH", book_meta{1, 21}},{"JONAH", book_meta{4, 17}},{"MICAH", book_meta{7, 20}},{"NAHUM", book_meta{3, 19}},{"HABAKKUK", book_meta{3, 20}},{"ZEPHANIAH", book_meta{3, 20}},{"HAGGAI", book_meta{2, 23}},{"ZECHARIAH", book_meta{14, 23}},{"MALACHI", book_meta{4, 18}},{"MATTHEW", book_meta{28, 75}},{"MARK", book_meta{16, 72}},{"LUKE", book_meta{24, 80}},{"JOHN", book_meta{21, 71}},{"ACTS", book_meta{28, 60}},{"ROMANS", book_meta{16, 39}},{"1CORINTHIANS", book_meta{16, 58}},{"2CORINTHIANS", book_meta{13, 33}},{"GALATIANS", book_meta{6, 31}},{"EPHESIANS", book_meta{6, 33}},{"PHILIPPIANS", book_meta{4, 30}},{"COLOSSIANS", book_meta{4, 29}},{"1THESSALONIANS", book_meta{5, 28}},{"2THESSALONIANS", book_meta{3, 18}},{"1TIMOTHY", book_meta{6, 25}},{"2TIMOTHY", book_meta{4, 26}},{"TITUS", book_meta{3, 16}},{"PHILEMON", book_meta{1, 25}},{"HEBREWS", book_meta{13, 40}},{"JAMES", book_meta{5, 27}},{"1PETER", book_meta{5, 25}},{"2PETER", book_meta{3, 22}},{"1JOHN", book_meta{5, 29}},{"2JOHN", book_meta{1, 13}},{"3JOHN", book_meta{1, 14}},{"JUDE", book_meta{1, 25}},{"REVELATION", book_meta{22, 29}}};
  // std::map<std::string, book_meta> book_borders = {{"HAHA", book_meta{1,2}}};
};
#endif // BOOK_H

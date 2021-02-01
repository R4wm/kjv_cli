- cant have "too" many initializers in a .cc source file
 - strangely you can do this in a .h header file though..
   - this is the reason bible.h is not text.cc
     - so im stuck with a weird place where i should not initialize things in header, but the cc file will error b/c there is too much

- cmake cant build for whatever reason
 - using regular g++ works though..


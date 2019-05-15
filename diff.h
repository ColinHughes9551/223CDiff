//
//  diff.h
//  diff
//
//  Created by Colin Hughes on 5/15/19.
//  Copyright © 2019 William McCarthy. All rights reserved.
//

#ifndef diff_h
#define diff_h

int files_equal(void);
void brief(const char* filename1, const char* filename2);
void identical(const char* filename1, const char* filename2);
void version(void);
void loadfiles(const char* filename1, const char* filename2);
void print_option(const char* name, int value);
void diff_output_conflict_error(void);
void setoption(const char* arg, const char* s, const char* t, int* value);
void showoptions(const char* file1, const char* file2);
void init_options_files(int argc, const char* argv[]);


#endif /* diff_h */

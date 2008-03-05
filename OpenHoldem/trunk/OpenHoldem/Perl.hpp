//////////////////////////////////////////////////////////////////////////
//
//  Author: TheHighFish
//
//  Created: 2007.12.11
//
//  Last change: 2008.01.29
//
//  Description: An interface to the Perl programing language 
//    for OpenHoldem
//
//////////////////////////////////////////////////////////////////////////

#pragma once

#include "stdafx.h"
#include <String>
#include <PerlEz.h>

using namespace std;


//  "PerlEzEvalString" returns all results as strings.
//    All OpenHoldems calls to perl functions should by 
//    design return only doubles, but the buffer is needed
//    for error messages sometimes. 
//    255 should be enough.
//
static const unsigned int the_Size_of_ResultBuffer = 255;

class Perl
{
  private:
	PERLEZHANDLE the_Interpreter;
    string the_actual_FormulaFile;
	char the_ResultBuffer[the_Size_of_ResultBuffer];
	bool Interpreter_not_loaded; 
	bool Formula_loaded;

 private:
	void send_Callback_Pointer_to_gws();
	void do_ErrorCheck(int the_ErrorCode);

  public: 			  
    Perl();
	~Perl();
    bool is_Perl_Symbol(const char *the_Symbol);
    double get_Perl_Symbol(const char *the_Symbol);

	
	//
    //  These functions should be used by the GUI
    //
  public:
    void edit_main_FormulaFile();
    void load_FormulaFile(string the_new_FormulaFile);
    void reload_FormulaFile();
	void unload_FormulaFile();
	bool is_a_Formula_loaded();
};



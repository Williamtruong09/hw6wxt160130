// William Truong wxt160130
#include <iostream>
#include "cdk.h"
#include<iomanip>
#include<fstream>
#include<stdint.h> 


#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Test Matrix"

using namespace std;

class BinaryFileHeader
{
public: 
  uint32_t magicNumber ; 
  uint32_t versionNumber ; 
  uint64_t numRecords ; 

} ;

const int maxRecordStringLength = 25 ; 

class BinaryFileRecord{

public: 
  uint8_t strLength ; 
  char stringBuffer[maxRecordStringLength] ;


} ;



int main()
{

  WINDOW    *window;
  CDKSCREEN  *cdkscreen;
  CDKMATRIX  *myMatrix;           // CDK Screen Matrix

  const char *rowTitles[] = {"R0", "R1", "R2", "R3","R4","R5"};
  const char *columnTitles[] = {"C0", "C1", "C2", "C3","C4","C5"};
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH,BOX_WIDTH,BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED,vMIXED,vMIXED,vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
   */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT,MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
			  boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */
  // setCDKMatrixCell(myMatrix, 2, 2, "Test Message");

  BinaryFileHeader *myHeader = new BinaryFileHeader() ; 
  
  BinaryFileRecord *myRecord = new BinaryFileRecord() ; // new records 

  ifstream binInFile("cs3377.bin",ios::in|ios::binary) ; // open binary file 

  binInFile.read((char *)myRecord,sizeof(BinaryFileRecord)) ; // reading in of the record 

  binInFile.read((char *)myHeader,sizeof(BinaryFileHeader)) ; // read iint he records
  cout <<"Version" <<   setprecision(10) << myHeader->versionNumber << endl ; 
  // setCDKMatrixCell(myMatrix,1,1,myHeader->magicNumber) ;
  // setCDKMatrixCell(myMatrix,1,2,myHeader->versionNumber);
  // setCDKMatrixCell(myMatrix,1,3,myHeader->numRecords) ; 

  drawCDKMatrix(myMatrix, true);    /* required  */
  
  unsigned char x ; 

  cin >> x ; 
  // Cleanup screen
  binInFile.close() ; 
  endCDK();
}

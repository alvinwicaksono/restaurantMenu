
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[18];
};
static const struct sqlcxp sqlfpn =
{
    17,
    "restaurantMenu.pc"
};


static unsigned int sqlctx = 10280707;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {13,4};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(unsigned char *, signed int *); }

 static const char *sq0001 = 
"select stock  from MENU where ID=:b0 for update of STOCK ";

 static const char *sq0005 = 
"select name ,price  from MENU            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,178,0,0,
5,0,0,1,57,0,9,165,0,0,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,167,0,0,1,0,0,1,0,2,4,0,0,
43,0,0,2,49,0,46,175,0,0,2,2,0,1,0,1,4,0,0,1,3,0,0,
66,0,0,3,0,0,29,176,0,0,0,0,0,1,0,
81,0,0,1,0,0,15,178,0,0,0,0,0,1,0,
96,0,0,0,0,0,27,210,0,0,4,4,0,1,0,1,97,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
127,0,0,0,0,0,56,212,0,0,1,1,0,1,0,3,102,0,0,
146,0,0,0,0,0,56,213,0,0,1,1,0,1,0,3,102,0,0,
165,0,0,5,41,0,9,235,0,0,0,0,0,1,0,
180,0,0,5,0,0,13,240,0,0,2,0,0,1,0,2,97,0,0,2,4,0,0,
203,0,0,5,0,0,15,251,0,0,0,0,0,1,0,
};


/* DECLARE SQL SECTION FOR DATABASE COLUMN */

/* exec sql begin declare section; */ 


int i, code, n;
char connData[50] = "C##ALVIN/dsasd@//10.211.55.3:1521/xe";
SQL_CURSOR c_menu;
SQL_CURSOR c_stock; 


struct
{
    char name[50];
    double price;
    double stock;
}menu_info;

/* exec sql end declare section; */ 

/* exec sql include sqlca;
 */ 
/*
 * $Header: precomp/public/sqlca.h /nt/2 2020/07/19 18:53:20 dgoddard Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */


#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <functional>
using namespace std;

class Menu {
    /* id variable */
    string name;
    double price;

    public:
    Menu(string s, double d) {
        name = s;
        price = d;
    };

    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }
};

class Order {
    Menu* menu;
    int quantity;

    public:
    Order(Menu* m, int q) {
        menu = m;
        quantity = q;
    }

    Menu* getMenu() {
        return menu;
    }

    int getQuantity() {
        return quantity;
    }
};

int checkError(int num1, int num2) {
    while (cin.fail() || num1 <= 0 || num1 > num2) {
        cin.clear();
        cin.ignore();

        cout << "You entered an incorrect value. Try again" << endl;
        cin >> num1;
    }

    return num1;
}

/* check for stock */
/* checkError(int num1, int num2) */
int CheckStock(int num1, int num2)
{
    while (cin.fail() || num1 <= 0 || num1 > num2) {
        cin.clear();
        cin.ignore();
        if(num1 > num2){
            cout << "\nQuantity melebihi stock yang tersedia. Stock yang tersedia: " << num2 << endl;    
             }
        
        cout << "You entered an incorrect value. Try again" << endl;
        cin >> num1;
    }

    return num1;
}

int checkError(int num1) {
    /* num1 < num2 ? */
    while (cin.fail() || num1 <= 0) {
        cin.clear();
        cin.ignore();

        cout << "You entered an incorrect value. Try again" << endl;
        cin >> num1;
    }

    return num1;
}

void checkConn()
{
if (sqlca.sqlcode==0) {
 
    } else {
            printf(sqlca.sqlerrm.sqlerrmc);
            printf(sqlca.sqlerrp);
            printf(sqlca.sqlwarn);
            printf(sqlca.sqlext);
        }

}


vector<Order*> orderingMenu(string menuType, map<int, Menu*> menuMap, string isOrdering, string stillOrdering) {
   
    vector<Order*> orders;

    while (isOrdering != "N" || isOrdering != "n") {
        cout << "\nDo you want to order " << menuType << "?\n";
        cin >> isOrdering;

        if (isOrdering == "N" || isOrdering == "n") {
            return orders;
        }

        if (isOrdering == "Y" || isOrdering == "y") {

            cout << "Please choose our " << menuType << " by selecting number below:\n";

            for (int i = 0; i < menuMap.size(); i++) {
                cout << i + 1 << ". " << menuMap[i + 1]->getName() << "\t\t Rp. " << menuMap[i + 1]->getPrice() << "\n";
            }

            while (stillOrdering != "N" || stillOrdering != "n") {
                if (stillOrdering == "Y" || stillOrdering == "y") {
                    cout << "\nYour " << menuType << " order number?\n";
                    cin >> code;
                    code = checkError(code, menuMap.size());

                    cout << "How many quantity?\n";
                    cin >> n;
                    /* query stock from database */

                    if (menuType=="Drink"){
                    code+=5;
                    }
                    

                    /* EXEC SQL DECLARE c_stock CURSOR FOR
                    SELECT stock
                    FROM MENU WHERE ID = :code
                     FOR UPDATE OF STOCK; */ 

               
                    
	                /* exec sql open c_stock; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 13;
                 sqlstm.arrsiz = 1;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.stmt = sq0001;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )5;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.sqlpfmem = (unsigned int  )0;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqcmod = (unsigned int )0;
                 sqlstm.sqhstv[0] = (         void  *)&code;
                 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         void  *)0;
                 sqlstm.sqinds[0] = (         int  )0;
                 sqlstm.sqharm[0] = (unsigned int  )0;
                 sqlstm.sqadto[0] = (unsigned short )0;
                 sqlstm.sqtdso[0] = (unsigned short )0;
                 sqlstm.sqphsv = sqlstm.sqhstv;
                 sqlstm.sqphsl = sqlstm.sqhstl;
                 sqlstm.sqphss = sqlstm.sqhsts;
                 sqlstm.sqpind = sqlstm.sqindv;
                 sqlstm.sqpins = sqlstm.sqinds;
                 sqlstm.sqparm = sqlstm.sqharm;
                 sqlstm.sqparc = sqlstm.sqharc;
                 sqlstm.sqpadto = sqlstm.sqadto;
                 sqlstm.sqptdso = sqlstm.sqtdso;
                 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		                
		                /* exec sql fetch c_stock into :menu_info.stock; */ 

{
                  struct sqlexd sqlstm;
                  sqlstm.sqlvsn = 13;
                  sqlstm.arrsiz = 1;
                  sqlstm.sqladtp = &sqladt;
                  sqlstm.sqltdsp = &sqltds;
                  sqlstm.iters = (unsigned int  )1;
                  sqlstm.offset = (unsigned int  )24;
                  sqlstm.selerr = (unsigned short)1;
                  sqlstm.sqlpfmem = (unsigned int  )0;
                  sqlstm.cud = sqlcud0;
                  sqlstm.sqlest = (unsigned char  *)&sqlca;
                  sqlstm.sqlety = (unsigned short)4352;
                  sqlstm.occurs = (unsigned int  )0;
                  sqlstm.sqfoff = (           int )0;
                  sqlstm.sqfmod = (unsigned int )2;
                  sqlstm.sqhstv[0] = (         void  *)&(menu_info.stock);
                  sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
                  sqlstm.sqhsts[0] = (         int  )0;
                  sqlstm.sqindv[0] = (         void  *)0;
                  sqlstm.sqinds[0] = (         int  )0;
                  sqlstm.sqharm[0] = (unsigned int  )0;
                  sqlstm.sqadto[0] = (unsigned short )0;
                  sqlstm.sqtdso[0] = (unsigned short )0;
                  sqlstm.sqphsv = sqlstm.sqhstv;
                  sqlstm.sqphsl = sqlstm.sqhstl;
                  sqlstm.sqphss = sqlstm.sqhsts;
                  sqlstm.sqpind = sqlstm.sqindv;
                  sqlstm.sqpins = sqlstm.sqinds;
                  sqlstm.sqparm = sqlstm.sqharm;
                  sqlstm.sqparc = sqlstm.sqharc;
                  sqlstm.sqpadto = sqlstm.sqadto;
                  sqlstm.sqptdso = sqlstm.sqtdso;
                  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



                    n = CheckStock(n,menu_info.stock);


                  /* update stock to database */
		              
                    
                        /* exec sql update menu set stock = :menu_info.stock-:n WHERE CURRENT OF c_stock; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 13;
                        sqlstm.arrsiz = 2;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.stmt = "update menu  set stock=(:b0-:b1) wher\
e rowid = :x";
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )43;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqhstv[0] = (         void  *)&(menu_info.stock);
                        sqlstm.sqhstl[0] = (unsigned int  )sizeof(double);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         void  *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned int  )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (         void  *)&n;
                        sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         void  *)0;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned int  )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqphsv = sqlstm.sqhstv;
                        sqlstm.sqphsl = sqlstm.sqhstl;
                        sqlstm.sqphss = sqlstm.sqhsts;
                        sqlstm.sqpind = sqlstm.sqindv;
                        sqlstm.sqpins = sqlstm.sqinds;
                        sqlstm.sqparm = sqlstm.sqharm;
                        sqlstm.sqparc = sqlstm.sqharc;
                        sqlstm.sqpadto = sqlstm.sqadto;
                        sqlstm.sqptdso = sqlstm.sqtdso;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		                /* exec sql commit; */ 

{
                  struct sqlexd sqlstm;
                  sqlstm.sqlvsn = 13;
                  sqlstm.arrsiz = 2;
                  sqlstm.sqladtp = &sqladt;
                  sqlstm.sqltdsp = &sqltds;
                  sqlstm.iters = (unsigned int  )1;
                  sqlstm.offset = (unsigned int  )66;
                  sqlstm.cud = sqlcud0;
                  sqlstm.sqlest = (unsigned char  *)&sqlca;
                  sqlstm.sqlety = (unsigned short)4352;
                  sqlstm.occurs = (unsigned int  )0;
                  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		
	                /* exec sql close c_stock; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 13;
                 sqlstm.arrsiz = 2;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )81;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



                    checkConn();
               
                     if (menuType=="Drink"){
                    code-=5;
                    }

                    orders.push_back(new Order(menuMap[code], n));
                   
                } else if (stillOrdering != "N" || stillOrdering != "n") {
                    cout << "Please Input the correct answer.\n";
                }

                cout << "Do you want to choose more " << menuType << "??\n";
                cin >> stillOrdering;
                if (stillOrdering == "N" || stillOrdering == "n") {
                    isOrdering == "N";
                    return orders;
                }
            }

        } else {
            cout << "Please input the correct answer\n";
        }
    }

    return orders;
}

int main() {

    /* exec sql connect :connData; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )96;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)connData;
    sqlstm.sqhstl[0] = (unsigned int  )50;
    sqlstm.sqhsts[0] = (         int  )50;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlstm.sqlcmax = (unsigned int )100;
    sqlstm.sqlcmin = (unsigned int )2;
    sqlstm.sqlcincr = (unsigned int )1;
    sqlstm.sqlctimeout = (unsigned int )0;
    sqlstm.sqlcnowait = (unsigned int )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



    /* EXEC SQL ALLOCATE :c_menu; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )127;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&c_menu;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ALLOCATE :c_stock; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )146;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&c_stock;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


 

     string isOrderingMenu = "y";
    string isOrderingFood;
    string isOrderingDrink;
    string stillOrderingFood = "y";
    string stillOrderingDrink = "y";

    
    map<int, Menu*> foods;
    map<int, Menu*> drinks;
    /* data get from database */
    /* for loop query from database */
    

 
   /* EXEC SQL DECLARE c_menu CURSOR FOR
              SELECT name, price
                FROM MENU; */ 

                

	/* exec sql open c_menu; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )165;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

        i=1;
        for(;;)
        {
		/* exec sql fetch c_menu into :menu_info.name, :menu_info.price; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )180;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.sqlpfmem = (unsigned int  )0;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)(menu_info.name);
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&(menu_info.price);
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) break;
}


		
        if (i<=5){
        foods.insert(make_pair(i, new Menu(menu_info.name, menu_info.price)));
        } else if (i>5){
        drinks.insert(make_pair(i-5, new Menu(menu_info.name, menu_info.price)));
        }
        
        i++;
        
	 }
	 /* exec sql close c_menu; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 13;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )203;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}




    vector<vector<Order*>> ordersList;

    cout << "\n-----------------------------";
    cout << "\nWelcome to Amazing Restaurant";
    cout << "\n-----------------------------\n";

    while (isOrderingMenu == "Y" || isOrderingMenu == "y") {

        ordersList.push_back(orderingMenu("Food", foods, isOrderingFood, stillOrderingFood));
        ordersList.push_back(orderingMenu("Drink", drinks, isOrderingDrink, stillOrderingDrink));

        cout << "\nDo you want to order more?\n";
        cin >> isOrderingMenu;
    }

    for (int i = 0; i < ordersList.size() - 1; i++) {
        vector<vector<Order*>>::iterator itr = ordersList.begin() + i;
        if (ordersList.at(i).empty()) {
            ordersList.erase(itr);
        }
    }

    if (!ordersList.at(0).empty()) {
        cout << "\nYou order:\n";
        cout << "No. \tMenu \t\tAmount \n";

        double total = 0;
        int counter = 0;
        for (int j = 0; j < ordersList.size(); j++) {
            for (int i = 0; i < ordersList.at(j).size(); i++) {
                counter++;
                cout << counter << "\t" << ordersList.at(j).at(i)->getMenu()->getName() << "\t\tRp.";
                cout << ordersList.at(j).at(i)->getQuantity() * ordersList.at(j).at(i)->getMenu()->getPrice();
                cout << "\n";

                total += ordersList.at(j).at(i)->getQuantity() * ordersList.at(j).at(i)->getMenu()->getPrice();
            }
        }

        cout << "Your total Meal is Rp." << total;
        cout << "\nThank you, please enjoy your meal and come again!\n\n";
    } else {
        cout << "\nThank you for coming!\n\n";
    } 

    return 0;
}
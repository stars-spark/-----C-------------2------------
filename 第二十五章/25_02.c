#include <stdio.h>
#include <locale.h>

int main(int argc,char* argv[]){
  char* str;

  if(argc > 1) str =  setlocale( LC_ALL, argv[1]);
  else  str =  setlocale( LC_ALL, "C");
  printf("Current Locate : %s\n",str);

  struct lconv *p = localeconv();

  printf("decimal_point = \"%s\"\n",p->decimal_point);
  printf("thousands_sep  = \"%s\"\n",p->thousands_sep );
  printf("grouping  = \"%d\"\n",*(p->grouping) );
  printf("mon_decimal_point  = \"%s\"\n",p->mon_decimal_point );
  printf("mon_thousands_sep  = \"%s\"\n",p->mon_thousands_sep );
  printf("mon_grouping  = \"%d\"\n",*(p->mon_grouping) );
  printf("positive_sign  = \"%s\"\n",p->positive_sign );
  printf("negative_sign  = \"%s\"\n",p->negative_sign );
  printf("currency_symbol  = \"%s\"\n",p->currency_symbol );
  printf("frac_digits  = \"%d\"\n",p->frac_digits );
  printf("p_cs_precedes  = \"%d\"\n",p->p_cs_precedes );
  printf("n_cs_precedes = \"%d\"\n",p->n_cs_precedes);
  printf("p_sep_by_space  = \"%c\"\n",p->p_sep_by_space );
  printf("n_sep_by_space  = \"%c\"\n",p->n_sep_by_space );
  printf("p_sign_posn  = \"%d\"\n",p->p_sign_posn );
  printf("n_sign_posn  = \"%d\"\n",p->n_sign_posn );
  printf("int_curr_symbol  = \"%c\"\n",p->int_curr_symbol );
  printf("int_frac_digits  = \"%d\"\n",p->int_frac_digits );
  printf("int_p_cs_precedes  = \"%c\"\n",p->int_p_cs_precedes );
  printf("int_n_cs_precedes  = \"%c\"\n",p->int_n_cs_precedes );
  printf("int_p_sep_by_space  = \"%c\"\n",p->int_p_sep_by_space );
  printf("int_n_sep_by_space  = \"%c\"\n",p->int_n_sep_by_space );
  printf("int_p_sign_posn  = \"%c\"\n",p->int_p_sign_posn );
  printf("int_n_sign_posn  = \"%c\"\n",p->int_n_sign_posn );
  return 0;
}

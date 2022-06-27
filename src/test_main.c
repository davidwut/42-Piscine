#include <stdio.h>
#include <string.h>

#include "header.h"

void	clear_grid_header(char **str);
void	test_nested_clear(char *str);

/*int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    printf("---------------------");
    printf("-> checking validity of '"CYA"1.ox\\n.\\n"NC"': "RED"%d"NC"\n", check("1.ox\n.\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"12.ox\\n.\\n"NC"': "RED"%d"NC"\n", check("12.ox\n.\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"0.ox\\n.\\n"NC"': "RED"%d"NC"\n", check("0.ox\n.\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"0.ox\\n"NC"': "RED"%d"NC"\n", check("0.ox\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"12.ox\\n......o.....\\n"NC"': "RED"%d"NC"\n", check("12.ox\n......o.....\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"12.ox\\n......x.....\\n"NC"': "RED"%d"NC"\n", check("12.ox\n......x.....\n"));

    printf("---------------------");
    printf("-> checking validity of '"CYA"12.ox\\n......o.....\\n......o.....\\n......o.....\\n......o.....\\n"NC"': "RED"%d"NC"\n", check("12.ox\n......o.....\n......o.....\n......o.....\n......o.....\n"));

        printf("---------------------");
    printf("-> checking validity of '"CYA"7.ox\\n......o.....\\n......o.....\\n......o.....\\n......o.....\\n......o.....\\n......o.....\\n......o.....\\n"NC"': "RED"%d"NC"\n", check("7.ox\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n"));
    
    
    char *str = strdup("7.ox\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n......o.....\n");
    printf("str: '%s'\n", str);
    s_grid_info *grid_info = get_grid_info(str);
    print_grid_info(grid_info);
    print_grid_from_str(str);
    return (0);
}
*/
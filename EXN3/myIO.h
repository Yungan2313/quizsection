void _check_args(int argc, char **argv, int *notation, int *action);
int _get_input(char **tokens);
void _free_tokens(char **tokens, int tokenLens);
void _exp_print(char **expression, int expLens, int mode);
void _calcResult_print(int result);
void _error_message(int condition);
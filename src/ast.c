#include "ast.h"

ast_node *create_translation_unit()
{
    ast_node *tu = (ast_node*)malloc(sizeof(ast_node));

    tu->node_type = AST_NODE_TRANSLATIONAL_UNIT;
    vec_init(&tu->child_nodes);

    return tu;
}

ast_node *add_program_unit(ast_node *parent, ast_node *child)
{
    vec_push(&parent->child_nodes, child);

    return parent;
}

ast_node_statements *create_statement_node(int node_type, void *child)
{
    ast_node_statements *stmt = (ast_node_statements*)malloc(sizeof(ast_node_statements));

    stmt->node_type = node_type;
    switch (node_type)
    {
        case AST_NODE_COMPOUND_STATEMENT:
            stmt->child_nodes.compound_statement = child;
            break;

        case AST_NODE_DECLARATION:
            stmt->child_nodes.declaration = child;
            break;  

        case AST_NODE_ASSIGNMENT:
            stmt->child_nodes.assignment = child;
            break;  

        case AST_NODE_CONDITIONAL_IF:
            stmt->child_nodes.if_else = child;
            break;

        case AST_NODE_PRINT_STRING_FUNCTION_CALL:
            stmt->child_nodes.print_string_function_call = child;
            break;

        case AST_NODE_PRINT_EXP_FUNCTION_CALL:
            stmt->child_nodes.print_expression_function_call = child;
            break;
                    
        case AST_NODE_FUNC_RETURN:
            stmt->child_nodes.return_statement = child;
            break;
            
        case AST_NODE_FUNC_CALL:
            stmt->child_nodes.function_call = child;
            break;

    }
    return stmt;
}

ast_node_compound_statement *create_compound_statement_node()
{
    ast_node_compound_statement *cmpd_stmt = (ast_node_compound_statement*)malloc(sizeof(ast_node_compound_statement));

    cmpd_stmt->node_type = AST_NODE_COMPOUND_STATEMENT;
    vec_init(&cmpd_stmt->child_nodes);

    return cmpd_stmt;
}

ast_node_compound_statement *add_compound_statement_node(ast_node_compound_statement *parent, ast_node_statements *child)
{
    vec_push(&parent->child_nodes, child);

    return parent;
}

ast_node_declaration *create_declaration_node(sym_ptr symbol, ast_node_expression *exp)
{
    ast_node_declaration *decl = (ast_node_declaration*)malloc(sizeof(ast_node_declaration));

    decl->node_type = AST_NODE_DECLARATION;
    decl->expression = exp;
    decl->symbol_entry = symbol;

    return decl;
}

ast_node_assignment *create_assignment_node(sym_ptr symbol, ast_node_expression *exp)
{
    ast_node_assignment *assgn = (ast_node_assignment*)malloc(sizeof(ast_node_assignment));

    assgn->node_type = AST_NODE_ASSIGNMENT;
    assgn->expression = exp;
    assgn->symbol_entry = symbol;

    return assgn;
}

ast_node_expression *create_expression_node(int node_type, int opt, int value, ast_node *left, ast_node *right)
{
    ast_node_expression *exp = (ast_node_expression*)malloc(sizeof(ast_node_expression));

    exp->node_type = node_type;
    exp->opt = opt;
    exp->value = value;
    exp->left = left;
    exp->right = right;

    return exp;
}

ast_node_conditional_if *create_conditional_if_node(ast_node_expression *condition, ast_node_compound_statement *body, ast_node_conditional_else_if *else_if, ast_node_compound_statement *else_node)
{
    ast_node_conditional_if *cond_if = (ast_node_conditional_if*)malloc(sizeof(ast_node_conditional_if));

    cond_if->node_type = AST_NODE_CONDITIONAL_IF;
    cond_if->condition = condition;
    cond_if->body = body;
    cond_if->else_if = else_if;
    cond_if->else_part = else_node;

    return cond_if;
}

ast_node_conditional_else_if *create_else_if_node()
{
    ast_node_conditional_else_if *cond_else_if = (ast_node_conditional_else_if*)malloc(sizeof(ast_node_conditional_else_if));

    cond_else_if->node_type = AST_NODE_CONDITIONAL_ELSE_IF;
    vec_init(&cond_else_if->else_if);

    return cond_else_if;
}

ast_node_conditional_else_if *add_else_if_node(ast_node_conditional_else_if *parent, ast_node_expression *condition, ast_node_compound_statement *body)
{
    ast_node_conditional_if *temp = (ast_node_conditional_if*)malloc(sizeof(ast_node_conditional_if));

    temp->node_type = AST_NODE_CONDITIONAL_ELSE_IF;
    temp->condition = condition;
    temp->body = body;
    temp->else_if = NULL;
    temp->else_part = NULL;

    vec_push(&parent->else_if, temp);

    return parent;
}

ast_node_function_def *create_function_def_node(sym_ptr symbol_entry, ast_node_param *params, ast_node_compound_statement *body, ast_node_expression *return_stmt)
{
    ast_node_function_def *function_def = (ast_node_function_def*)malloc(sizeof(ast_node_function_def));

    function_def->node_type = AST_NODE_FUNCTION_DEFS;
    function_def->symbol_entry = symbol_entry;
    function_def->params = params;
    function_def->body = body;
    function_def->return_statment = return_stmt;

    return function_def;
}

ast_node_param *create_parameter_node()
{
    ast_node_param *params = (ast_node_param*)malloc(sizeof(ast_node_param));

    params->node_type = AST_NODE_FUNC_PARAM;
    vec_init(&params->variable);

    return params;
}

ast_node_param *add_parameter_node(ast_node_param *parent, ast_node_variable *var)
{
    vec_push(&parent->variable, var);

    return parent;
}

ast_node_function_call *create_function_call_node(sym_ptr symbol, ast_node_arguments *arguments)
{
    ast_node_function_call *function_call = (ast_node_function_call*)malloc(sizeof(ast_node_function_call));

    function_call->node_type = AST_NODE_FUNC_CALL;
    function_call->symbol_entry = symbol;
    function_call->args = arguments;

    return function_call;
}

ast_node_arguments *create_argument_node()
{
    ast_node_arguments *arguments = (ast_node_arguments*)malloc(sizeof(ast_node_arguments));

    arguments->node_type = AST_NODE_FUNC_ARGS;
    vec_init(&arguments->arguments);

    return arguments;
}

ast_node_arguments *add_argument_node(ast_node_arguments *parent, ast_node_expression *argument)
{
    vec_push(&parent->arguments, argument);

    return parent;
}

ast_node_constant *create_constant_node(int data_type, int value)
{
    ast_node_constant *cnst = (ast_node_constant*)malloc(sizeof(ast_node_constant)); 

    cnst->node_type = AST_NODE_CONSTANT;
    cnst->data_type = data_type;
    cnst->value = value;

    return cnst;
}

ast_node_variable *create_variable_node(int data_type, sym_ptr symbol)
{
    ast_node_variable *var = (ast_node_variable*)malloc(sizeof(ast_node_variable));

    var->node_type = AST_NODE_VARIABLE;
    var->data_type = data_type;
    var->symbol_entry = symbol;

    return var;
}

ast_node_print_string_function_call *create_print_string_function_call_node(char *string, int add_newline)
{
    ast_node_print_string_function_call *print_function_call = (ast_node_print_string_function_call*)malloc(sizeof(ast_node_print_string_function_call));

    print_function_call->node_type = AST_NODE_PRINT_STRING_FUNCTION_CALL;
    print_function_call->add_newline = add_newline;
    print_function_call->string = string;

    return print_function_call;
}

ast_node_print_expression_function_call *create_print_expression_function_call_node(ast_node_expression *expression, int add_newline)
{
    ast_node_print_expression_function_call *print_function_call = (ast_node_print_expression_function_call*)malloc(sizeof(ast_node_print_expression_function_call));

    print_function_call->node_type = AST_NODE_PRINT_EXP_FUNCTION_CALL;
    print_function_call->add_newline = add_newline;
    
    print_function_call->expression = expression;

    return print_function_call;
}

void ast_node_dump(ast_node* ast)
{
    ast_node_type(ast->node_type);

    int i = 0;
    ast_node *temp;
    
    vec_foreach(&ast->child_nodes, temp, i)
    {
        ast_node_type(temp->node_type);   
    }
}

void ast_node_type(int node_type)
{
    switch (node_type)
    {
        case AST_NODE:
            printf("ast node");
            break;

        case AST_NODE_TRANSLATIONAL_UNIT:
            printf("ast translational unit");
            break;

        case AST_NODE_STATEMENTS:
            printf("ast statements");
            break;

        case AST_NODE_FUNCTION_DEFS:
            printf("ast function definition");
            break;

        case AST_NODE_COMPOUND_STATEMENT:
            printf("ast compound statement");
            break;

        case AST_NODE_DECLARATION:
            printf("ast declaration");
            break;

        case AST_NODE_ASSIGNMENT:
            printf("ast assignment");
            break;

        case AST_NODE_ARITHMETIC_EXP:
            printf("ast arithmetic expression");
            break;

         case AST_NODE_BOOLEAN_EXP:
            printf("ast boolean expression");
            break;

        case AST_NODE_RELATIONAL_EXP:
            printf("ast relational expression");
            break;

        case AST_NODE_LOGICAL_EXP:
            printf("ast logical expression");
            break;

        case AST_NODE_CONDITIONAL_IF:
            printf("ast if statement");
            break;

        case AST_NODE_CONDITIONAL_ELSE_IF:
            printf("ast elseif statement");
            break;

        case AST_NODE_CONSTANT_CHAR:
            printf("ast_constant_char");
            break;

        case AST_NODE_VARIABLE:
            printf("ast variable");
            break;

        case AST_NODE_FUNC_CALL:
            printf("ast function call");
            break;
        
        case AST_NODE_FUNC_PARAM:
            printf("ast parameters");
            break;
        
        case AST_NODE_FUNC_ARGS:
            printf("ast arguments");
            break;


        case AST_NODE_PRINT_STRING_FUNCTION_CALL:
            printf("print_string function call");
            break;

        case AST_NODE_PRINT_EXP_FUNCTION_CALL:
            printf("print_expression function call");
            break;

        default:
            printf("ast invalid");
            break;
    }
    printf("\n");
}
import re

# Regular expressions for different types of tokens
integers_number = re.compile(r'^\d+$')
variables = re.compile(r'^[_a-zA-Z][_a-zA-Z0-9]*$')
token_delimiters = {
    '+': 'PLUS',
    '-': 'MINUS',
    '*': 'MULTIPLY',
    '/': 'DIVIDE',
    '%': 'MODULE',
    ':-': 'LT',
    '+:': 'GT',
    ':-=': 'LTE',
    '+:=': 'GTE',
    '==': 'DOUBLEEQUAL',
    '=': 'EQUAL',
    '!=': 'NOTEQUAL',
    '(': 'LPAREN',
    ')': 'RPAREN',
    '{': 'LBRACK',
    '}': 'RBRACK'
}
keywords = {'if', 'else', 'print', 'while'}

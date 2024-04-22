# src/LexicalAnalyzer.py
import re
from scanner_dependencies import integers_number, variables, token_delimiters, keywords

class LexicalAnalyzer:
    def __init__(self):
        self.integers_number = integers_number
        self.variables = variables
        self.token_delimiters = token_delimiters
        self.keywords = keywords

    def get_word_type(self, word):
        if self.integers_number.match(word):
            return "Number"
        elif word in self.keywords:
            return "Keyword"
        elif self.variables.match(word):
            return "Identifier"
        else:
            for delim_pattern, delim_label in self.token_delimiters.items():
                if delim_pattern == word:
                    return f"Delimiter ({delim_label})"
        return "Unknown"

    def tokenize(self, input_code):
        tokens = re.split(r'(\s+|\b)', input_code)
        return [token for token in tokens if token.strip() or token == '\n']


    def scan(self, input_code):
        tokens = self.tokenize(input_code)
        symbol_table = []
        line_number = 1

        for token in tokens:
            if token.strip() or token == '\n':  #Considerar '\n' como um token
                if token == '\n':
                    line_number += 1
                    continue  # Pula a adição de uma entrada de quebra de linha na tabela de símbolos
                token_type = self.get_word_type(token)
                symbol_table.append({
                    'Line': line_number,
                    'Identifier': token,
                    'Label': token_type
                })
        return symbol_table


    def run(self, file_path):
        try:
            with open(file_path, 'r') as file:
                input_code = file.read()
            symbol_table = self.scan(input_code)
            for entry in symbol_table:
                print(entry)
        except FileNotFoundError:
            print(f"Error: The file {file_path} was not found.")
        except IOError:
            print(f"Error: An error occurred while reading the file {file_path}.")


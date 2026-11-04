import os
import sys

class EmptyFileError(Exception):
  """Raise when input or output file is empty"""
  pass

def split_file_into_lines(file_path: str) -> list[str]:
    with open(file_path, "r") as f:
        if os.fstat(f.fileno()).st_size == 0:
            raise EmptyFileError
        else:
            content =  f.readlines()
            if content[-1].strip() == "":
               return content[:-1]
            else:
               return content

          

def check_solution(input_file_path:str, output_file_path:str) -> tuple[bool, str|None]:
  return False, ""


if __name__ == "__main__":
  # Usage: python checker.py input.txt output.txt
  if len(sys.argv) < 3:
    print("Usage: python checker.py <input_file> <output_file>")
    sys.exit(1)

  success, message = check_solution(sys.argv[1], sys.argv[2])
  print(message)
  sys.exit(0 if success else 1)

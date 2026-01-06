import os

def rename_files_in_dir(directory, name_prefix="r_file", file_extension=".txt"):
  try:
    files = os.listdir(directory)
    for i, filename in enumerate(files):
      new_name = f"{name_prefix}_{i+1}{file_extension}"
      old_path = os.path.join(directory, filename)
      new_path = os.path.join(directory, new_name)
      os.rename(old_path, new_path)
      print(f"Renamed: {filename} -> {new_name}")
  except FileNotFoundError:
    print("Directory not found. Please check the path.")
  except Exception as e:
    print(f"An error occurred: {e}")
    
if __name__ == "__main__":
  folder_path = "/Users/farhasayed/Desktop/Git/Farha-Sayed/Devops/Python-Scripting/Testfiles"
  rename_files_in_dir(folder_path)

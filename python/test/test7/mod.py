import importlib

def explore_module():
    module_name = input("Enter module name to explore: ")
    try:
        module = importlib.import_module(module_name)
        print("Available Attributes in", module_name, "module:")
        print(dir(module))
    except ModuleNotFoundError:
        print("Module not found!")
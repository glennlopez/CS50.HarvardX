# libs to import



# Prompt user to type in some text
def calculate_colemanLaiuIndex(l, w, s):
    index = float(0.0)
    L = float(l / w * 100.0)
    S =  float(s / w * 100.0)
    index = round((0.0588 * L) - (0.296 * S) - 15.8);
    return index


# Output the reading grade level

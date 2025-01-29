def compress (String):
    result_string = ""
    num_repeating_letters = 1

    #Add in first character
    result_string += string[0]

    #iterate skipping last one
    for i in range(len(String) - 1):
        if(string[i] == string[i+1]):
            num_repeating_letters += 1
        else:
            if (num_repeating_letters > 1):
                result_string += str(num_repeating_letters)
            result_string += string[i+1]
            num_repeating_letters = 1
        #print last one
        if(num_repeating_letters > 1):
            result_string += str(num_repeating_letters)
        return result_string

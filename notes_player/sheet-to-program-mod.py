OCTAVE_SHIFT=1
NOTE_SYMBOLS=['c','C','d','D','e','f','F','g','G','a','A','b'];

sheet=[]

with open("sheet.txt","r") as file:
    i=0
    for line in file:
        if(line.strip().isdigit()):
            i+=1
            continue
        if(len(sheet)<=i):
            sheet.append(['  ' for j in range(len(line.strip())-3)])
        octave=0
        for j,c in enumerate(line.strip()):
            if(j==0):
                octave=int(c)-OCTAVE_SHIFT
            else:
                if(c in NOTE_SYMBOLS):
                    sheet[i][j-2]=f"{octave}{c}"

with open("sheet_modified.txt","w") as file:
    for line in sheet:
        for note in line:
            file.write(f"{note}\n")
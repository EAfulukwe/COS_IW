# importing csv module
import csv
import os


def makeUpdate(folder, file):
    # csv file name
    filename = folder + '/' + file

    # initializing the titles and rows list
    fields = []
    rows = []

    # reading csv file
    with open(filename, 'r') as csvfile:
        # creating a csv reader object
        csvreader = csv.reader(csvfile)

        # extracting field names through first row
        fields = next(csvreader)

        # extracting each data row one by one
        for row in csvreader:
            rows.append(row)

        #CORRECTLY FORMATS DATES
        for row in rows:
            if (row[0][4] == row[0][6]): # for single digit month
                row[0] = row[0][:5] + '0' + row[0][5:]
            if (row[0][9] == ' '): # for single digit date
                row[0] = row[0][:8] + '0' + row[0][8:]
            if (row[0][12] == ':'): # single digit hour
                row[0] = row[0][:11] + '0' + row[0][11:]
            if (row[0][15] == ':'): #single digit minute
                row[0] = row[0][:14] + '0' + row[0][14:]
            if (row[0][18] == ':'): # for single digit second
                row[0] = row[0][:17] + '0' + row[0][17:]
            # replace ms colon with dot
            row[0] = row[0][:19] + '.' + row[0][20:]

            if (len(row[0][20:]) == 1): # for single digit ms
                row[0] = row[0][:20] + '00' + row[0][20:]
            elif (len(row[0][20:]) == 2): # for double digit ms
                row[0] = row[0][:20] + '0' + row[0][20:]
        
        #REMOVING ALL DUPLICATE TIME ENTRIES
        prev = -1
        i = 0
        while i < len(rows):
            if (prev == -1 or prev != rows[i][0]):
                prev = rows[i][0]
                i += 1
            elif (prev == rows[i][0]):
                rows = rows[:i] + rows[i+1:]

        # Remove all data that is within 00:00:00.087 within
        prev = rows[0][0]
        i = 1
        while i < len(rows):
            val1 = float('0' + prev[19:])
            val2 = float('0' + rows[i][0][19:])
            if (val2 < val1):
                val2 += 1
            if (val2 - val1 < 0.087):
                rows = rows[:i] + rows[i+1:]
            else:
                prev = rows[i][0]
                i += 1
        
        # name of csv file
        filename2 = folder + ' U/' + file
        
        # writing to csv file
    with open(filename2, 'w') as csvfile:
        # creating a csv writer object
        csvwriter = csv.writer(csvfile)
    
        # writing the fields
        csvwriter.writerow(fields)
    
        # writing the data rows
        csvwriter.writerows(rows)


def updateJumps():
    folder = 'Jumps'
    for file in os.listdir(folder):
        makeUpdate(folder, file)

def updateSpins():
    folder = 'Spins'
    for file in os.listdir(folder):
        makeUpdate(folder, file)

def updateSpecificJump():
    folder = 'Jumps'
    makeUpdate(folder, 'Video4_LLJIV.csv')

# Defining main function 
def main(): 
    updateJumps()
    # updateSpins()
    # updateSpecificJump() 
  
  
# Using the special variable  
# __name__ 
if __name__=="__main__": 
    main() 

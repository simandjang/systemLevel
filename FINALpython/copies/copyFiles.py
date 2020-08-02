#1/usr/bin/python
from shutil import copyfile as cpf

def move_file(d_name, f_name):
	from_dir = d_name + '/' + f_name
	c_out_d_name = '../FINALc/copies/' + f_name 
	py_out_d_name = '../FINALpython/copies/' + f_name
	cpf(from_dir, c_out_d_name)
	cpf(from_dir, py_out_d_name)

f = open("FINALinstruction", "r")
lines = f.readlines()
cur_dir = '.'

for each_l in lines[4:]:
	if len(each_l) < 3 or each_l.startswith('total'):
		continue
	elif each_l.startswith('./'):
		cur_dir = each_l[:-3]
	else:
		file_name = ' '.join(each_l.split()[1:])
		move_file(cur_dir, file_name)

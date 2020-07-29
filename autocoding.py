name = input('输入类名: ')
var_type = []
var_name = []
num = int(input('输入成员变量个数: '))
print('开始定义成员变量')
for i in range(0, num):
    inp = input()
    type_ = inp.split(' ')[0]
    name_ = inp.split(' ')[1]
    var_type.append(type_)
    var_name.append(name_)
file = open(name + '.h', 'a+')
file.close()
file = open(name + '.h', 'w')
file.write('class ' + name + ' {\n')
for i in range(0, num):
    file.write('    ' + var_type[i] + ' ' + var_name[i] + ';\n')
file.write('public:\n')
for i in range(0, num):
    file.write('    void ' + 'set_' + var_name[i] + '(' + var_type[i] + ' ' + '_v);\n')
    file.write('    ' + var_type[i] + ' get_' + var_name[i] + '() const;\n')
file.write('}\n')
file.close()

file = open(name + '.cpp', 'a+')
file.close()
file = open(name + '.cpp', 'w')
file.write('#include "' + name + '.h"\n\n')
for i in range(0, num):
    file.write('void ' + name + '::' + 'set_' + var_name[i] + '(' + var_type[i] + ' ' + '_v) {\n')
    file.write('    ' + var_name[i] + ' = _v;\n')
    file.write('}\n\n')
    file.write(var_type[i] + ' ' + name + '::' + ' get_' + var_name[i] + '() const {\n')
    file.write('    return ' + var_name[i] + ';\n')
    file.write('}\n\n')
file.close()

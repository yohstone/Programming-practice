
import scapy
from scapy.all import *

#coding: utf-8
#lcss
def get_lcs(string1, string2):

	string1_list = list(string1)
	string2_list = list(string2)
	lcs_list = []
	for i in range(len(string1_list)):
		flag = 0
		lcs = ''
		for j in range(i, len(string1_list)):
			for k in range(flag, len(string2_list)):
				if string1_list[j] == string2_list[k]:
					lcs += string1_list[j]
					flag = k+1
		lcs_list.append((len(lcs), lcs))
	#print len(lcs_list)#lcss num
	max_str = sorted(lcs_list, reverse=True)[0]

	return max_str
#calculate the distance between string1 and string2
def cal_dist(string1, string2):
	max_str = get_lcs(string1, string2)
	lcs_len = max_str[0]
	max_len = len(string1) if len(string1) > len(string2) else len(string2)
	return 1-round(lcs_len/float(max_len), 2)



def str_to_hex(s):
    return ' '.join([hex(ord(c)).replace('0x', '') for c in s])

def hex_to_str(s):
    return ''.join([chr(i) for i in [int(b, 16) for b in s.split(' ')]])

def str_to_bin(s):
    return ' '.join([bin(ord(c)).replace('0b', '') for c in s])

def bin_to_str(s):
    return ''.join([chr(i) for i in [int(b, 2) for b in s.split(' ')]])





try: 
	s1 = PcapReader('7ci-afterguolv.pcap')
	count = -1 
	num = 0
	mydict = {}

	while count != 0:
		#count -= 1
		data = s1.read_packet()
		if data is None:
			break
		else:
			p = repr(data)
			#str = data.sport
			#str1 = 
			#print p
			#print type(p)
			loaddata = data['Raw'].load
			slen = len(data['Raw'].load) # data length
			if mydict.has_key(slen):
				mydict[slen][ mydict[slen]['num'] ] = loaddata
				mydict[slen]['num'] += 1
			else:
				mydict[slen] = {}
				mydict[slen] = { 0 : loaddata}
				mydict[slen]['num'] = 1
			
			#for i in loaddata:
				#print type(i)
				#print('%#x'% ord(i))
			#print repr(data)
	s1.close()
	#print mydict[11]
	str1 = mydict[11][0]
	str2 = mydict[11][1]
	#print type(str1)
	#print list(bytes(str2))
	print list(mydict.items())
	lcs = get_lcs(str1, str2)
	#print lcs[0] #max lcss length
	print cal_dist(str1, str2)
	# packets = rdpcap('87s-7ci-qifei.pcap')
	# for data in packets:
	# 	if 'UDP' in data:
	# 		s = repr(data)
	# 		#print(s)
	# 		print(data['Raw'].load)
	# 		#print( data['UDP'] )
	# 		#break
except Exception as e:
	print(e)











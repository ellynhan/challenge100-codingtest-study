def solution(new_id):
    
    new_id = new_id.lower()
    new_id = ''.join([x for x in new_id if x in ['-', '_', '.'] or x.isalnum()])
    new_id = '.'.join([x for x in new_id.split('.') if x != ''])
    l = len(new_id)
    if l > 3:
        if l > 15: new_id = new_id[:15]
        if new_id[0] == '.': new_id = new_id[1:]
        if new_id[-1] == '.': new_id = new_id[:-1]
    else: 
        if l == 0: new_id = 'a'
        new_id += new_id[-1] * (3-len(new_id))
        
    return new_id

function solution(new_id) {
    let answer = '';
    new_id = new_id.toLowerCase();
    new_id = new_id.replace(/[^0-9a-z\-\_\.]/g, '');
    new_id = new_id.replace(/(\.{2,})/g, '.');
    new_id = new_id.replace(/^\.|\.$/g, '');
    if (!new_id) new_id = 'a'
    new_id = new_id.slice(0,15);
    new_id = new_id.replace(/\.$/g, '');
    if(new_id.length <= 2) new_id += (new_id.slice(-1).repeat(3 - new_id.length));
    
    answer = new_id;
    return answer;
}

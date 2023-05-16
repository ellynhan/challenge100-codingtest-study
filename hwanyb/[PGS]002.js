function solution(common) {
    if (common[2] - common[1] === common[1] - common[0]) {
        // 등차수열에 대한 로직
        return common.pop() + common[1] - common[0];
    } else {
        // 등비수열에 대한 로직
        return common.pop() * (common[1] / common[0]);
    }
}
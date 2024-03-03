/*

프로그래머스 / 베스트앨범 / 레벨 3
https://programmers.co.kr/learn/courses/30/lessons/42579

< 소요 시간 >
2시간

< 프로그래밍 계획 >

- 1차 시도

  1. 노래 정보를 담은 배열을 생성 [... ,[장르, 재생수, 고유번호], ...]
  2. Map으로 장르를 키로 묶어서 총 재생수, 노래모음 배열을 value로 넣음
  3. 장르별로 최다 재생 수로 정렬 후 2개까지 자름
  4. 장르별로 2개까지 얻은 노래를 1차원 배열로 고유번호로 리턴

*/

// 1차 시도
function solution(genres, plays) {
  const genresMap = new Map();

  genres
    .map((genre, index) => [genre, plays[index], index])
    .forEach(([genre, play, id]) => {
      const genreData = genresMap.get(genre) || { total: 0, songs: [] };
      const newGenreData = {
        total: genreData.total + play,
        songs: [...genreData.songs, [play, id]],
      };
      genresMap.set(genre, newGenreData);
    });

  const result = [...genresMap.entries()]
    .sort((a, b) => b[1].total - a[1].total)
    .map((genreData) =>
      genreData[1].songs
        .sort((a, b) => b[0] - a[0])
        .slice(0, 2)
        .map((song) => song[1])
    )
    .flat();

  console.log(result);
  return result;
}

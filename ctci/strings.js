function benchmark(callback){
  var start = new Date();
  callback.call();
  var end = new Date();
  console.log(end.getTime() - start.getTime()+" ms");
  return;
}

//1.1
/*console.log((function str_uniq(str){
  for(var i = 0; i < str.length; i++){
  var chr = str[i];
  for(var a = i+1; a < str.length; a++){
  if (str[i] === str[a]){ return "false"; }
  }
  }
  return "true";
  })(process.argv[2].trim()));*/

//1.2
/*benchmark(function(){
  var str1 = process.argv[2].trim();
  var str2 = process.argv[3].trim();
  console.log((function isPermutation(str1, str2){
    if(str1.length !== str2.length){ return "false"; }
    var freqObj = function(str){
      var freq = {};
      for(var i = 0; i < str.length; i++){
        if(!freq[str[i]]){
          freq[str[i]] = 0;
        }
        freq[str[i]] += 1;
      }
      return freq;
    };
    var strObj1 = freqObj(str1);
    var strObj2 = freqObj(str2);
    for(var i = 0; i < str1.length; i++){
      if(strObj1[str1[i]] !== strObj2[str1[i]]){
        return "false";
      }
    }
    return "true";
  })(str1, str2));
});*/

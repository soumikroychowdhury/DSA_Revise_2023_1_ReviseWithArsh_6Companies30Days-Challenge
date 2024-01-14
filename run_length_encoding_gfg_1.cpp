string encode(string src)
{     
  string ans="";
  int count=1;
  char c=src[0];
  for(int i=1;i<src.size();i++){
      if(src[i]==c) count++;
      else{
          ans+=c+to_string(count);
          count=1;
          c=src[i];
      }
  }
  if(count) ans+=c+to_string(count);
  return ans;
}   
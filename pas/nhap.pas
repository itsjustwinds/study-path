var
        s:string;
        i,n:longint;
        x,y:string;
begin
        readln(n);
        s:='';
        str(n,s);
       { for i:=1 to length(s) div 2 do
        begin  }
                x:=s[1];y:=s[length(s)-1+1];

              {  insert(y,s,1);
                delete(s,1+1,1);}

                insert(x,s,length(s)-1+1);
              {  delete(s,length(s)-1+2,1);}
              x:=s[length(s)-1+2];
       { end; }
        write(x);
        readln;
end.
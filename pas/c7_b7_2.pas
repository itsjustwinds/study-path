 var
        s,s1,k:string;
        max:longint;
 begin
        readln(s);
        s:=s+' ';max:=0;
        while pos(' ',s)<>0 do
        begin
                s1:=copy(s,1,pos(' ',s));
                if length(s1)>max then
                begin
                        max:=length(s1);
                        k:=s1;
                end;
                delete(s,1,pos(' ',s));
        end;
        write(k);
readln
end.


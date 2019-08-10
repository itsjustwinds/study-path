var
        s,s1:string;
        i:longint;
begin
        writeln('nhap xau chuoi');
        readln(s);
        s1:='ch';
        for i:=1 to length(s) do
                while pos(s1,s)<>0 do delete(s,pos(s1,s),2);
        write(s);
        readln
end.
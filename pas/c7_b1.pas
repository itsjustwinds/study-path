var
        s:string;
        i,j:longint;
begin
        writeln('nhap chuoi:');
        readln(s);
        for i:=1 to length(s) do
                s[i]:=upcase(s[i]);
        write(s);
        readln
end.
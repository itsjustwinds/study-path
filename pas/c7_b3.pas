var     s:string;
        i,dems,demc:longint;
begin
        writeln('nhap chuoi');
        readln(s);
        dems:=0;
        demc:=0;
        for i:=1 to length(s) do
                begin
                if s[i] in ['0'..'9'] then inc(dems);
                if s[i] in ['a'..'z'] then inc(demc);
                if s[i] in ['A'..'Z'] then inc(demc);
                end;
        writeln('so ki tu so la:',dems);
        write('so ki tu chu la:',demc);
        readln
end.
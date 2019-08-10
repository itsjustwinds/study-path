var
        x,a,b:int64;
        dd:array['0'..'9'] of boolean;
        d:int64;
        i:longint;
        s:string;
procedure nhap;
begin
        readln(x,a,b);
        readln(s);
        fillchar(dd,sizeof(dd),false);
        for i:=1 to length(s) do
                dd[s[i]]:=true;
end;
function check(n:int64):boolean;
var     s:string;
        i:longint;
begin
        str(n,s);
        for i:=1 to length(s) do
                if not(dd[s[i]]) then exit(false);
        exit(true);
end;
procedure xuly;
var     d:int64;
        kt:boolean;
        kq:int64;
begin
                if a mod x=0 then d:=a div x
                else d:=(a div x)+1;
                kq:=1;
                while not(check(x*d)) do inc(d);
                kt:=true;
                while kt do
                begin
                        inc(d);
                        if b>=d*x then
                        begin
                                if check(x*d) then
                                        inc(kq);
                        end
                        else kt:=false;
                end;
                write(kq);
end;
begin
        assign(input,'vnum.inp');
        assign(output,'vnum.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
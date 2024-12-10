import { Handlers, PageProps } from "$fresh/server.ts";

const NAMES = ["Alice", "Bob", "Charlie", "Dave", "Eve", "Frank"];

interface Data {
  results: string[];
  query: string;
}

export const handler: Handlers<Data> = {
  GET(req, ctx) {
    const url = new URL(req.url);
    const query = url.searchParams.get("q") || "";
    const results = NAMES.filter((name) => name.includes(query));
    return ctx.render({ results, query });
  },
};

export default function Page({ data }: PageProps<Data>) {
  const { results, query } = data;
  return (
    <div class="px-4 py-8 mx-auto bg-[#86efac]">
        <div class="max-w-screen-md mx-auto flex flex-col items-center justify-center">
            <p>Fill out your info</p>
            <form method="post" action= "/add">
                <div>
                    <input id="name" type="text" name="name"></input>
                    <label>Name</label>
                </div>
                <div>
                    <input id="country" type="text" name="city"></input>
                    <label>City</label>
                </div>
                <div>
                    <input id="country" type="text" name="country"></input>
                    <label>Country</label>
                </div>
                <div>
                    <input id="birthday" type="text" name="birthday"></input>
                    <label>Birthday</label>
                </div>
                <div>
                    <input id="email" type="text" name="email"></input>
                    <label>Email</label>
                </div>
                <button type="submit">Submit</button>
            </form>
            <form method = "get" action="/list">
                <button type="list">List People</button>
            </form>
        </div>
    </div>
  );
}
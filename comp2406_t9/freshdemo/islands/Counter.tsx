import type { Signal } from "@preact/signals";
import { Button } from "../components/Button.tsx";

const buttonIncrement = 3;

interface CounterProps {
  count: Signal<number>;
}

export default function Counter(props: CounterProps) {
  return (
    <div class="flex gap-8 py-6">
      <Button onClick={() => props.count.value -= buttonIncrement}>-{buttonIncrement}</Button>
      <p class="text-3xl tabular-nums">{props.count}</p>
      <Button onClick={() => props.count.value += buttonIncrement}>+{buttonIncrement}</Button>
      <h1>BUTTON</h1>
    </div>
  );
}

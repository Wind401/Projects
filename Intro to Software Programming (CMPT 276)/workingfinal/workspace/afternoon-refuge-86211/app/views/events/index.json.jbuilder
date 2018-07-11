json.array!(@events) do |event|
  json.extract! event, :id, :event_name, :desription, :date, :location
  json.url event_url(event, format: :json)
end
